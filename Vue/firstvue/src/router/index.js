import Vue from 'vue'
import Router from 'vue-router'
import Content from '../components/Content'

Vue.use(Router);

//路由跳转路径
export default new Router({
    routes: [{
            path: '/content',
            name:'Content',
            component: Content
        }]
})