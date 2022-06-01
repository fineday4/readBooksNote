import Vue from 'vue'
import Router from 'vue-router'
import Login from '../views/login'
import Main from '../views/Main'
import MemberList from '../views/Member/MemberList'
import MemberLevel from '../views/Member/MemberLevel'
import NotFound from '../views/NotFound'

Vue.use(Router);
export default new Router({
    mode: 'history',
    routes:[
        {
            path: '/login',
            name: 'Login',
            component: Login
        },
        {
            path: '/main/:name',
            name: 'Main',
            component: Main,
            children:[
                {
                    path: '/member/list/:id',
                    name: 'MemberList',
                    component: MemberList,
                    props: true
                },
                {
                    path: '/member/level',
                    name: 'MemberLevel',
                    component: MemberLevel
                },
                {
                    path:'/goMain/:name',
                    redirect: '/main/:name'
                },
                {
                    path:'*',
                    component: NotFound
                }
            ]
        }
]
})